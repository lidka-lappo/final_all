from mendeleev import element

def print_isotope_ranges():
    # Iterate through elements from Hydrogen to Einsteinium
    for symbol in range(1, 100):
        try:
            elem = element(symbol)
            isotopes = elem.isotopes
            if isotopes:
                # Get the highest and lowest mass numbers
                max_mass = max(isotopes, key=lambda x: x.mass_number).mass_number
                min_mass = min(isotopes, key=lambda x: x.mass_number).mass_number
                print(f"{max_mass}, ")
                #print(f"{elem.symbol}: Lowest Mass Number = {min_mass}, Highest Mass Number = {max_mass}")
            else:
                print(f"{elem.symbol}: No known isotopes.")
        except ValueError:
            # Skip if the element doesn't exist
            pass

if __name__ == "__main__":
    print_isotope_ranges()
